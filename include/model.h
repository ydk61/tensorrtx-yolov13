#pragma once

#include <assert.h>
#include <string>
#include "NvInfer.h"

nvinfer1::IHostMemory* buildEngineYolov13Det(nvinfer1::IBuilder* builder, nvinfer1::IBuilderConfig* config,
                                            nvinfer1::DataType dt, const std::string& wts_path, float& gd, float& gw,
                                            int& max_channels, std::string& type);

nvinfer1::IHostMemory* buildEngineYolov13Det_debug(nvinfer1::IBuilder* builder, nvinfer1::IBuilderConfig* config,
                                                   nvinfer1::DataType dt, const std::string& wts_path, float& gd,
                                                   float& gw, int& max_channels, std::string& type);