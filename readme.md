## Introduction

Yolov13 model supports TensorRT-8.

Detection training code [link](https://github.com/iMoonLab/yolov13/releases/tag/yolov13)


## Environment

* cuda 11.6
* cudnn 8.9.1.23
* tensorrt 8.6.1.6
* opencv 4.8.0
* ultralytics 8.3.63

## Support

* [x] YOLOV13-det support FP32/FP16/INT8 and C++ API


## Config

* Choose the YOLOV13 sub-model n/s/l/x from command line arguments.
* Other configs please check [src/config.h](src/config.h)

## Build and Run (Detection)

1. generate .wts from pytorch with .pt, or download .wts from model zoo

```shell
# Download ultralytics
wget https://github.com/iMoonLab/yolov13/releases/tag/yolov13 -O ultralytics-8.3.63.zip
# Unzip ultralytics
unzip ultralytics-8.3.63.zip
cd ultralytics-8.3.63
# Training your ownself models
to download other models, replace 'yolov13n.pt' with 'yolov13s.pt', 'yolov13l.pt', or 'yolov13x.pt'
# Generate .wts
cp [PATH-TO-TENSORRTX]/yolov13/gen_wts.py .
python gen_wts.py -w yolov13n.pt -t detect -o yolov13n.wts 
# A file 'yolov13n.wts' will be generated.
```

2. build tensorrtx/yolov13 and run
```shell
cd [PATH-TO-TENSORRTX]/yolov13
mkdir build
cd build
cmake ..
make
```



### Detection
```shell
cp [PATH-TO-ultralytics]/yolov13n.wts .
# Build and serialize TensorRT engine
./yolov13-det -s yolov13n.wts yolo13n.engine [n/s/l/x]
# Run inference
./yolov13-det -d yolo13n.engine ../images [c/g]
# results saved in build directory
```

## INT8 Quantization
1. Prepare calibration images, you can randomly select 1000s images from your train set.
     For coco, you can also download my calibration images `coco_calib` from 
     [GoogleDrive](https://drive.google.com/drive/folders/1s7jE9DtOngZMzJC1uL307J2MiaGwdRSI?usp=sharing) 
     or [BaiduPan](https://pan.baidu.com/s/1GOm_-JobpyLMAqZWCDUhKg) pwd: a9wh
2. unzip it in yolo11/build
3. set the macro `USE_INT8` in src/config.h and make again
4. serialize the model and test

.......  but I meet a mistake when I try to use the int8  ......
activation_8(47): error: identifier "inff" is undefined

1 error detected in the compilation of "activation_8".

[06/28/2025-10:42:42] [E] [TRT] 1: Unexpected exception NVRTC error: NVRTC_ERROR_COMPILATION
Build engine successfully!
Assertion failed: serialized_engine, file E:\tensorrtx-master\yolov13\yolov13_det.cpp, line 23
























## More Information
See the readme in [home page.](https://github.com/wang-xinyu/tensorrtx)
