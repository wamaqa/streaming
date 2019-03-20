//
// Created by wmq on 2019/3/15.
//

#ifndef PROJECT_SOCKETDATA_H
#define PROJECT_SOCKETDATA_H

enum DataType {
	STR = 0,
	PNG = 1,
	JPG = 2
};

struct SocketData
{
	DataType dataType;
	int Sum;
	int index;
	int size;
	int status;
	char buff[4088];
};


#endif //PROJECT_SOCKETDATA_H
