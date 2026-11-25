cmake_minimum_required(VERSION 3.29)
project(EchecsBavards)

set(CMAKE_CXX_STANDARD 20)

add_executable(EchecsBavards
        main.cxx
        Piece.cxx
        Echiquier.cxx
        Reine.cxx
        Cavalier.cxx
        Pion.h
)

