#pragma once

enum LogLevel {
    FATAL,    // 最高级：致命错误，程序通常会立即终止
    ERROR,    // 错误：严重问题，但程序可能继续运行
    WARNING,     // 警告：潜在问题，但不影响当前功能（注意：正确拼写是 WARNING 或 WARN）
    INFO,     // 信息：一般性运行信息，用于追踪流程
    DEBUG,    // 调试：详细调试信息，通常只在开发/测试时开启
};