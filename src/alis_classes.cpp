#include "alis_classes.h"

// Again, DataBase implementation is here but imagine that it 
// is an external library that connects to the network and fetches
// the records from a cloud-based database/server.
bool DataBase::login(std::string username, std::string password) {
	return true;
}

bool DataBase::logout(std::string username) {
	return true;
}

int DataBase::fetchRecord() {
	return -1;
}
