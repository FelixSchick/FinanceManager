cmake_minimum_required(VERSION 3.27)
project(FinanceManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(FinanceManager main.cpp
        provider/UIProvider.cpp
        provider/UIProvider.h
        objects/Expense.cpp
        objects/Expense.h
        objects/Expense.h
        provider/ExpenseProvider.cpp
        provider/ExpenseProvider.h
        provider/DataProvider.cpp
        provider/DataProvider.h)
