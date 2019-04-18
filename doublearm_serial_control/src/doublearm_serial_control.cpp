#include "ros/ros.h"
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include "sensor_msgs/JointState.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstddef>
using std::string;
using std::stringstream;
#define M_PI 3.14159
int range_test_L(float str1,float str2,float str3,float str4,float str5);
void jointstatesCallback(const sensor_msgs::JointStateConstPtr& msg);

string chToHex_L(unsigned char ch);
string chToHex_H(int ch);
int chToHex_HH(int ch);
int chToHex_LL(unsigned char ch);
int ConvertHexChar(char ch);

serial::Serial ros_ser;       //声明串口对象

//回调函数
void jointstatesCallback(const sensor_msgs::JointStateConstPtr& msg)
{
	stringstream str;
  
	str<<"right_joint2: pos:"<<msg->position[0]
	   <<"left_joint2: pos:"<<msg->position[1]
	   <<"right_joint3: pos:"<<msg->position[2]
       <<"left_joint3: pos:"<<msg->position[3]
	   <<"right_joint4: pos:"<<msg->position[4]
	   <<"left_joint4: pos:"<<msg->position[5]
       <<"right_joint5: pos:"<<msg->position[6]
	   <<"left_joint5: pos:"<<msg->position[7]
	   <<"right_joint6: pos:"<<msg->position[8]
       <<"left_joint6: pos:"<<msg->position[9]
	   <<"left_palm_joint: pos:"<<msg->position[10]
	   <<"right_palm_joint: pos:"<<msg->position[11]
       <<"left_thumb_joint: pos:"<<msg->position[12]
	   <<"right_thumb_joint: pos:"<<msg->position[13]       
	   <<"left_index_finger_joint: pos:"<<msg->position[14]
       <<"right_index_finger_joint:"<<msg->position[15]
	   <<"left_middle_finger_joint: pos:"<<msg->position[16]
	   <<"right_middle_finger_joint: pos:"<<msg->position[17]
       <<"left_third_finger_joint: pos:"<<msg->position[18]
	   <<"right_third_finger_joint: pos:"<<msg->position[19]
	   <<"left_little_finger_joint: pos:"<<msg->position[20]
       <<"right_little_finger_joint: pos:"<<msg->position[21]<<std::endl;
     ROS_INFO_STREAM("Writing to serial port" );
        //i=int(msg->position[0]);55 55 08 03 01 E8 03 00 E8 03
     ROS_INFO_STREAM(range_test_L(900,1900,0,1.57,msg->position[0]));
     ROS_INFO_STREAM(chToHex_H(range_test_L(1900,1000,0,M_PI/2,msg->position[0])));
     ROS_INFO_STREAM(chToHex_L(range_test_L(1900,1000,0,M_PI/2,msg->position[0])));
     
    //ROS_INFO_STREAM(chToHex_L('U','U','A'-57,'A'-62,'A'-64,'A'+167,'A'-62,'A'-62,'A'+167,'A'-62,));*/
    
    char str_str[]={85,85,71,3, 22,232,3,11,232,3,1,232,3,2,232,3,3,232,3,4,232,3,5,232,3,11,232,3,1,232,3,2,232,3,3,232,3,4,232,3,5,232,3,11,232,3,1,232,3,2,232,3,3,232,3,4,232,3,5,232,3,11,232,3,1,232,3,2,232,3,3,232,3};
    
    str_str[7]=11;
    str_str[8]=chToHex_LL(range_test_L(1900,1000,0,M_PI/2,msg->position[0]));;
    str_str[9]=chToHex_HH(range_test_L(1900,1000,0,M_PI/2,msg->position[0]));;
    str_str[10]=1;
    str_str[11]=chToHex_LL(range_test_L(2150,1300,0,M_PI/2,msg->position[2]));;
    str_str[12]=chToHex_HH(range_test_L(2150,1300,0,M_PI/2,msg->position[2]));;
    str_str[13]=2;
    str_str[14]=chToHex_LL(range_test_L(1000,2400,-M_PI/2,M_PI/3,msg->position[4]));;
    str_str[15]=chToHex_HH(range_test_L(1000,2400,-M_PI/2,M_PI/3,msg->position[4]));;
    str_str[16]=3;
    str_str[17]=chToHex_LL(range_test_L(2200,1000,0,M_PI/2,msg->position[6]));;
    str_str[18]=chToHex_HH(range_test_L(2200,1000,0,M_PI/2,msg->position[6]));;
    str_str[19]=4;
    str_str[20]=chToHex_LL(range_test_L(500,2600,-M_PI/2,M_PI/2,msg->position[8]));;
    str_str[21]=chToHex_HH(range_test_L(500,2600,-M_PI/2,M_PI/2,msg->position[8]));;
    str_str[22]=5;
    str_str[23]=chToHex_LL(range_test_L(1650,2200,0,M_PI/3,msg->position[11]));;
    str_str[24]=chToHex_HH(range_test_L(1650,2200,0,M_PI/3,msg->position[11]));;
    str_str[25]=6;//
    str_str[26]=chToHex_LL(range_test_L(1600,800,0,M_PI/2,msg->position[13]));;
    str_str[27]=chToHex_HH(range_test_L(1600,800,0,M_PI/2,msg->position[13]));;
    str_str[28]=7;//
    str_str[29]=chToHex_LL(range_test_L(1800,800,0,M_PI/2,msg->position[15]));;
    str_str[30]=chToHex_HH(range_test_L(1800,800,0,M_PI/2,msg->position[15]));;
    str_str[31]=8;//
    str_str[32]=chToHex_LL(range_test_L(1000,2000,0,M_PI/2,msg->position[17]));;
    str_str[33]=chToHex_HH(range_test_L(1000,2000,0,M_PI/2,msg->position[17]));;
    str_str[34]=9;//
    str_str[35]=chToHex_LL(range_test_L(1600,800,0,M_PI/2,msg->position[19]));;
    str_str[36]=chToHex_HH(range_test_L(1600,800,0,M_PI/2,msg->position[19]));;
    str_str[37]=10;//
    str_str[38]=chToHex_LL(range_test_L(1600,800,0,M_PI/2,msg->position[21]));;
    str_str[39]=chToHex_HH(range_test_L(1600,800,0,M_PI/2,msg->position[21]));;
    str_str[40]=31;//
    str_str[41]=chToHex_LL(range_test_L(1100,2100,0,M_PI/2,msg->position[1]));;
    str_str[42]=chToHex_HH(range_test_L(1100,2100,0,M_PI/2,msg->position[1]));;
    str_str[43]=30;//
    str_str[44]=chToHex_LL(range_test_L(950,1300,0,M_PI/6,msg->position[3]));;
    str_str[45]=chToHex_HH(range_test_L(950,1300,0,M_PI/6,msg->position[3]));;
    str_str[46]=29;//
    str_str[47]=chToHex_LL(range_test_L(2200,500,-M_PI/2,M_PI/3,msg->position[5]));;
    str_str[48]=chToHex_HH(range_test_L(2200,500,-M_PI/2,M_PI/3,msg->position[5]));;
    str_str[49]=28;//
    str_str[50]=chToHex_LL(range_test_L(1400,500,0,M_PI/2,msg->position[7]));;
    str_str[51]=chToHex_HH(range_test_L(1400,500,0,M_PI/2,msg->position[7]));;
    str_str[52]=27;//
    str_str[53]=chToHex_LL(range_test_L(2500,500,-M_PI/2,M_PI/2,msg->position[9]));;
    str_str[54]=chToHex_HH(range_test_L(2500,500,-M_PI/2,M_PI/2,msg->position[9]));;
    str_str[55]=26;//
    str_str[56]=chToHex_LL(range_test_L(1500,1000,0,M_PI/3,msg->position[10]));;
    str_str[57]=chToHex_HH(range_test_L(1500,1000,0,M_PI/3,msg->position[10]));;
    str_str[58]=25;//
    str_str[59]=chToHex_LL(range_test_L(1200,2000,0,M_PI/2,msg->position[12]));;
    str_str[60]=chToHex_HH(range_test_L(1200,2000,0,M_PI/2,msg->position[12]));;
    str_str[61]=24;//
    str_str[62]=chToHex_LL(range_test_L(1800,500,0,M_PI/2,msg->position[14]));;
    str_str[63]=chToHex_HH(range_test_L(1800,500,0,M_PI/2,msg->position[14]));;
    str_str[64]=23;
    str_str[65]=chToHex_LL(range_test_L(1000,2100,0,M_PI/2,msg->position[16]));;
    str_str[66]=chToHex_HH(range_test_L(1000,2100,0,M_PI/2,msg->position[16]));;
    str_str[67]=22;
    str_str[68]=chToHex_LL(range_test_L(2000,500,0,M_PI/2,msg->position[18]));;
    str_str[69]=chToHex_HH(range_test_L(2000,500,0,M_PI/2,msg->position[18]));;
    str_str[70]=21;
    str_str[71]=chToHex_LL(range_test_L(1000,2000,0,M_PI/2,msg->position[20]));;
    str_str[72]=chToHex_HH(range_test_L(1000,2000,0,M_PI/2,msg->position[20]));;
    str_str[73]=0;
    //char str_str[8]='A'+167;
    //char str_str[9]='A'-62;
    ROS_INFO_STREAM(str_str);
    ros_ser.write(str_str);
}

int range_test_L(float str1,float str2,float str3,float str4,float str5)
{

    float sl = str1;
    float sh = str2;
    float al = str3;
    float ah = str4;
    float ip = str5;
    int op=int(((ip-al)*(sh-sl))/(ah-al)+sl);
    
    return op;
}

/******************************************
                    转换函数
******************************************/
int ConvertHexChar(char ch)
{
        if((ch >= '0') && (ch <= '9'))
            return ch-'0';
        else if((ch >= 'A') && (ch <= 'F'))
            return ch-'A'+10;
        else if((ch >= 'a') && (ch <= 'f'))
            return ch-'a'+10;
        else return ch-ch;//不在0-f范围内的会发送成0
}
string chToHex_L(unsigned char ch)
{
	const string hex = "0123456789ABCDEF";
 
	stringstream ss;
	ss << hex[ch >> 4] << hex[ch & 0xf];
 
	return ss.str();
}
string chToHex_H(int ch)
{
	const string hex = "0123456789ABCDEF";
 
	stringstream ss;
	ss << hex[ch >> 12] << hex[ch >> 8];
 
	return ss.str();
}
int chToHex_LL(unsigned char ch)
{
	const string hex = "0123456789ABCDEF";
 
	stringstream ss;
	
    int S_L=int((ConvertHexChar(hex[ch >> 4])*16)+ConvertHexChar(hex[ch & 0xf]));
	return S_L;
}
int chToHex_HH(int ch)
{
	const string hex = "0123456789ABCDEF";
 
	stringstream ss;
	
    int S_H=int((ConvertHexChar(hex[ch >> 12])*16)+ConvertHexChar(hex[ch >> 8]));
	return S_H;
}
int main (int argc, char** argv)
{
     ros::init(argc, argv, "doublearm_serial_control");  //初始化节点
     ros::NodeHandle n;                        //声明节点句柄
     //订阅主题/joint_states，并配置回调函数
     ros::Subscriber command_sub = n.subscribe("/joint_states", 1, jointstatesCallback);
     //发布主题sensor
     ros::Publisher sensor_pub = n.advertise<std_msgs::String>("sensor", 1000);
 
     try
     {
         //设置串口属性，并打开串口
         ros_ser.setPort("/dev/ttyUSB0");
         ros_ser.setBaudrate(9600);
         serial::Timeout to = serial::Timeout::simpleTimeout(1000);
         ros_ser.setTimeout(to);
         ros_ser.open();
     }
     catch (serial::IOException& e)
     {
         ROS_ERROR_STREAM("Unable to open port ");
         return -1;
     }
 
     //检测串口是否已经打开，并给出提示信息 
     if(ros_ser.isOpen()){
         ROS_INFO_STREAM("Serial Port opened");
     }
     else
        {
         return -1;
        }
 
     //指定循环的频率
     ros::Rate loop_rate(10);
 
     while(ros::ok()){
 
         //处理ROS的信息，比如订阅消息,并调用回调函数
         ros::spinOnce();
 
         if(ros_ser.available())
         {
             ROS_INFO_STREAM("Reading from serial port");
             std_msgs::String serial_data;
             //获取串口数据

             serial_data.data = ros_ser.read(ros_ser.available());
             ROS_INFO_STREAM("Read: " << serial_data.data);
             //将串口数据发布到主题sensor
             sensor_pub.publish(serial_data);
         }
         loop_rate.sleep();
     }
 }
