# 建立 Container
```
docker build -t yolov5/ncnn_cpp .
docker run -it --gpus=all --mount source=yolo_cpp,target=/docker_mount --name yolo_cpp yolov5/ncnn_cpp
```

建立完成後，可以到 `\\wsl.localhost\docker-desktop-data\data\docker\volumes
`

找到本機 mount 資料夾