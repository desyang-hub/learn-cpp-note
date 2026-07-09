// yolo_postprocess.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>

struct Detection {
    float x, y, w, h;
    float confidence;
    int class_id;
};

class YOLOPostprocessor {
public:
    // 模拟后处理函数
    static std::vector<Detection> processImage(float* data, int num_anchors) {
        std::vector<Detection> detections;
        detections.reserve(100);
        
        for (int i = 0; i < num_anchors; ++i) {
            float* box = data + i * 84;
            float conf = box[4];
            
            // 阈值过滤
            if (conf > 0.5f) {
                Detection det;
                det.x = box[0];
                det.y = box[1];
                det.w = box[2];
                det.h = box[3];
                det.confidence = conf;
                
                // 找最大类别分数
                int max_class = 0;
                float max_score = 0;
                for (int c = 5; c < 84; ++c) {
                    if (box[c] > max_score) {
                        max_score = box[c];
                        max_class = c - 5;
                    }
                }
                det.class_id = max_class;
                detections.push_back(det);
            }
        }
        
        return detections;
    }
    
    // 批量处理 - 使用OpenMP
    static std::vector<std::vector<Detection>> processBatch(
        float* all_outputs, 
        int batch_size, 
        int num_anchors) 
    {
        std::vector<std::vector<Detection>> all_detections(batch_size);
        
        // ✅ 并行处理每个图像
        #pragma omp parallel for num_threads(4) schedule(dynamic)
        for (int b = 0; b < batch_size; ++b) {
            float* image_data = all_outputs + b * (84 * num_anchors);
            all_detections[b] = processImage(image_data, num_anchors);
        }
        
        return all_detections;
    }
};

int main() {
    // 模拟数据：batch_size=8, 每个图像有8400个anchor
    const int BATCH_SIZE = 8;
    const int NUM_ANCHORS = 8400;
    const int OUTPUT_SIZE = 84 * NUM_ANCHORS;
    
    std::vector<float> outputs(BATCH_SIZE * OUTPUT_SIZE);
    
    // 填充模拟数据
    for (int i = 0; i < outputs.size(); ++i) {
        outputs[i] = (float)rand() / RAND_MAX;
    }
    
    // 后处理
    auto start = std::chrono::high_resolution_clock::now();
    auto results = YOLOPostprocessor::processBatch(
        outputs.data(), BATCH_SIZE, NUM_ANCHORS
    );
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Processed " << BATCH_SIZE << " images in " 
              << duration.count() << " ms" << std::endl;
    
    // 显示结果统计
    for (int b = 0; b < BATCH_SIZE; ++b) {
        std::cout << "Image " << b << ": " 
                  << results[b].size() << " detections" << std::endl;
    }
    
    return 0;
}