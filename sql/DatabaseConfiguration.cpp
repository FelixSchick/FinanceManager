//
// Created by schic on 19/12/2024.
//

#include "DatabaseConfiguration.h"
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <memory>
#include <iostream>

class DatabaseConnection {
private:
    std::unique_ptr<sql::Connection> connection;

public:
    DatabaseConnection(const DatabaseConfig& config) {
        try {
            sql::Driver* driver = get_driver_instance();
            connection.reset(driver->connect(config.getHost(), config.getUser(), config.getPassword()));
            connection->setSchema(config.getDatabase());
        } catch (sql::SQLException& e) {
            std::cerr << "Database connection error: " << e.what() << std::endl;
            throw;
        }
    }

    sql::Connection* getConnection() const { return connection.get(); }
};

