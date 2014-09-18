# CMakeのバージョン(適当)
cmake_minimum_required(VERSION 2.6)
# リリースビルド用オプション
set(CMAKE_C_FLAGS_TELEASE "-Wall -O2")
# デバッグビルド用オプション
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
# ビルドタイプ（下記の場合、Release）
set(CMAKE_BUILD_TYPE Release)

# プロジェクト名
project(4thRobot)
# リンクライブラリの追加
add_subdirectory(Gim30)

# Mainビルド
add_executable (main main.c)
# ターゲットリンクライブラリ
target_link_libraries(main Gim30)



