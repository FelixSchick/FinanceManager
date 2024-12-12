cmake_minimum_required(VERSION 3.27)
project(FinanceManager)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(FinanceManager main.cpp
        provider/UIProvider.cpp
        provider/UIProvider.h
        objects/Transaction.cpp
        objects/Transaction.h
        objects/Transaction.h
        provider/TransactionProvider.cpp
        provider/TransactionProvider.h
        provider/DataProvider.cpp
        provider/DataProvider.h
        provider/DateProvider.cpp
        provider/DateProvider.h
        objects/User.h
        objects/IBan.h
        objects/IBan.h
        objects/IBan.cpp
)
