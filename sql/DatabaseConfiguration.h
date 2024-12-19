//
// Created by schic on 19/12/2024.
//

#ifndef FINANCEMANAGER_DATABASECONFIGURATION_H
#define FINANCEMANAGER_DATABASECONFIGURATION_H

#include <string>

class DatabaseConfig {
private:
    std::string host;
    std::string user;
    std::string password;
    std::string database;
    unsigned int port;

public:
    DatabaseConfig(const std::string& host, const std::string& user, const std::string& password,
                   const std::string& database, unsigned int port = 3306)
            : host(host), user(user), password(password), database(database), port(port) {}

    const std::string& getHost() const { return host; }
    const std::string& getUser() const { return user; }
    const std::string& getPassword() const { return password; }
    const std::string& getDatabase() const { return database; }
    unsigned int getPort() const { return port; }
};


#endif //FINANCEMANAGER_DATABASECONFIGURATION_H
