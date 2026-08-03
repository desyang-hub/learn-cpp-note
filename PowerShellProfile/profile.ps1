# ✅ 完整 UTF-8 编码设置（两行缺一不可）
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8   # 接收外部程序输出（如 Python 报错）
$OutputEncoding = [System.Text.Encoding]::UTF8             # 发送给外部程序的输入


# --- Linux 常用命令补全 (Zero-Dependency) ---

# which 
function which {
    param([string]$Name)
    $cmd = Get-Command $Name -ErrorAction SilentlyContinue
    if ($cmd) {
        # 优先返回 Source（外部程序路径），否则返回定义类型
        if ($cmd.Source) { $cmd.Source }
        elseif ($cmd.CommandType -eq 'Alias') { "Alias: $($cmd.Definition)" }
        elseif ($cmd.CommandType -eq 'Function') { "Function: $($cmd.Name)" }
        else { $cmd.CommandType.ToString() }
    } else {
        Write-Error "which: no $Name in (`$env:PATH)"
    }
}

# ln
function ln {
    param(
        [switch]$s,
        [Parameter(ValueFromRemainingArguments)]
        [string[]]$Arguments
    )

    if ($Arguments.Count -lt 2) {
        Write-Error "Usage: ln [-s] <target> <link>"; return
    }

    # ⚠️ 关键修复：Unix ln 语法是 ln <target> <link>
    $target = $Arguments[-2]   # 'build'
    $link   = $Arguments[-1]   # 'build-test'

    if (-not (Test-Path $target)) {
        Write-Error "Target '$target' does not exist. Junction requires an existing target."
        return
    }

    $absTarget = (Resolve-Path $target).Path

    if (Test-Path $absTarget -PathType Container) {
        cmd /c mklink /J "`"$link`"" "`"$absTarget`""
    } elseif ($s) {
        cmd /c mklink "`"$link`"" "`"$absTarget`""
    } else {
        cmd /c mklink /H "`"$link`"" "`"$absTarget`""
    }
}

# touch: 创建空文件或更新时间戳
function touch {
    param([string[]]$Path)
    foreach ($p in $Path) {
        if (Test-Path -LiteralPath $p) {
            (Get-Item -LiteralPath $p).LastWriteTime = Get-Date
        } else {
            New-Item -ItemType File -Path $p -Force | Out-Null
        }
    }
}


# head / tail: 查看文件首尾
function head { param([int]$n = 10, [Parameter(Mandatory)][string]$Path) Get-Content -LiteralPath $Path -TotalCount $n }
function tail { param([int]$n = 10, [Parameter(Mandatory)][string]$Path) Get-Content -LiteralPath $Path -Tail $n }

# wc: 统计行数/单词数/字符数
function wc {
    param([string]$Path)
    if (-not $Path) { Write-Error "Usage: wc <file>"; return }
    $content = Get-Content -LiteralPath $Path -Raw
    $lines   = (Get-Content -LiteralPath $Path).Count
    $words   = ($content -split '\s+' | Where-Object { $_ }).Count
    $chars   = $content.Length
    [PSCustomObject]@{ Lines = $lines; Words = $words; Chars = $chars; File = $Path }
}

# df: 磁盘空间概览 (模拟 df -h)
function df {
    Get-PSDrive -PSProvider FileSystem | Where-Object { $_.Used -or $_.Free } |
    Select-Object Name,
        @{N='Size(GB)'; E={[math]::Round(($_.Used + $_.Free)/1GB, 2)}},
        @{N='Used(GB)'; E={[math]::Round($_.Used/1GB, 2)}},
        @{N='Free(GB)'; E={[math]::Round($_.Free/1GB, 2)}},
        @{N='Use%';     E={if(($_.Used+$_.Free) -gt 0){'{0:P0}' -f ($_.Used/($_.Used+$_.Free))}else{'N/A'}}} |
    Format-Table -AutoSize
}

# tree: 目录树 (调用 Windows 自带 cmd tree)
function tree { cmd /c tree /F /A @args }

# grep: 简化版递归搜索 (输出格式贴近 Linux grep)
function grep {
    param(
        [Parameter(Mandatory)][string]$Pattern,
        [string]$Path = '.',
        [switch]$i,
        [switch]$r
    )
    $files = if ($r) { Get-ChildItem -LiteralPath $Path -Recurse -File } 
             else     { Get-ChildItem -LiteralPath $Path -File }
    $params = @{ Pattern = $Pattern }
    if ($i) { $params['CaseSensitive'] = $false }
    $files | Select-String @params | ForEach-Object {
        "$($_.RelativePath):$($_.LineNumber): $($_.Line.Trim())"
    }
}