#include <ros/ros.h>
#include <string.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pointcloud");
    ROS_INFO("Start PCL Reading Node...");

    ros::NodeHandle n;
    ros::Publisher pcl_pub = n.advertise<sensor_msgs::PointCloud2> ("pcl_output",1);

    sensor_msgs::PointCloud2 output;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    //std::string filename = "/home/hit/catkin_ws_eric/src/pointcloud/PCDdata/hand.pcd";
    std::string filename = "/home/hit/write_pcd.pcd";

    //pcl::io::loadPCDFile("/home/hit/catkin_ws_eric/src/pointcloud/src/blade.pcd",cloud);
    pcl::io::loadPCDFile(filename, cloud);
    //std::cout<<filename<<std::endl;


    pcl::toROSMsg(cloud,output);
    output.header.frame_id = "odom";

    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        ROS_INFO("ROS is working...");
        std::cout<<filename<<std::endl;
        pcl_pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}
