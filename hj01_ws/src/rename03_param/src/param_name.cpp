#include "ros/ros.h"

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    
    //使用  ros::param   设置参数
    ros::param::set("/set_A",100); //全局,和命名空间以及节点名称无关
    ros::param::set("set_B",100); //相对,参考命名空间
    ros::param::set("~set_C",100); //私有,参考命名空间与节点名称

    //使用  ros::NodeHandle   设置参数

nh.setParam("/nh_A",100); //全局,和命名空间以及节点名称无关

nh.setParam("nh_B",100); //相对,参考命名空间

ros::NodeHandle nh_private("~");
nh_private.setParam("nh_C",100);//私有,参考命名空间与节点名称

    return 0;
}