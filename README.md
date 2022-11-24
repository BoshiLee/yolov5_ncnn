# yolov5_ncnn

第一次使用請參考 [環境建立](build_enviorment.md)

1. 環境建好後，到 mount 資料夾將 [yolov5](yolov5) 複製進去

2. 進入 Container
`docker exec -it yolov5/ncnn_cpp bash`

3. 使用 ls 確認當前目錄所有資料夾，如果為以下則可進行下一步

    ![](/misc/Screenshot%202022-11-24%20161421.png)

4. 建置 cmake
    ```=shell
    cd yolov5
    mkdir -p build
    cd build
    cmake ..
    make -j$(nproc)
    ```
    ![](/misc/build_finished.png)
5. 執行程式
    ```
    ./yolov5_ncnn ../test.jpg
    ```
    結果應如下圖

    ![](/misc/process_results.png)
    輸出結果
    
    ![](/misc/result.jpeg)



