#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>

std::string map_file;

void cloudCB(const sensor_msgs::PointCloud2 &input)
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(input, cloud);
    // private_nh.getParam("global_map_file",map_file);
    // pcl::io::savePCDFileASCII (map_file, cloud);

    pcl::io::savePCDFileASCII ("/home/hit/write_pcd.pcd", cloud);
}

int main (int argc, char **argv)
{
    ros::init (argc, argv, "pcd_write");

    ros::NodeHandle nh;
    ros::Subscriber bat_sub = nh.subscribe("/camera/depth/points", 10000, cloudCB);

    ros::spin();

    return 0;
}
