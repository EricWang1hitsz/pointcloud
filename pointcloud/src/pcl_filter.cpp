#include <iostream>
#include <string.h>

//pcl filter
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/voxel_grid.h>

//pcl
#include <pcl_conversions/pcl_conversions.h>

//sensor message
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>

//ROS
#include <ros/ros.h>

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloud;

class pcl_filter
{
public:
    //constructor function
    pcl_filter()
    {
        cloud_sub = nh_.subscribe<sensor_msgs::PointCloud2>("/camera/depth/points", 1, &pcl_filter::pointcloud_filter_cb, this);
        cloud_pub = nh_.advertise<sensor_msgs::PointCloud2>("/cloud_filter_", 1);

    }

    void pointcloud_filter_cb(const sensor_msgs::PointCloud2::ConstPtr &msg_in)
    {
        //eric_wang:print the frame_id of the pointcloud;
        std::cout<<"camera_pointcloud_frame:"<<msg_in->header.frame_id<<std::endl;
        //eric_wang:creat a PointCloud object;
        PointCloud:: Ptr cloud_ros (new PointCloud);
        pcl::fromROSMsg(*msg_in, *cloud_ros);

        //pointcloud filter;
        pcl::VoxelGrid<pcl::PointXYZRGB> pass;
        pass.setInputCloud(cloud_ros);
        pass.setLeafSize(0.025, 0.025, 0.025);
        PointCloud:: Ptr tmp (new PointCloud);
        pass.filter(*tmp);
        tmp->swap(*cloud_ros);
        std::cout<<"the size of the pointcloud"<<cloud_ros->size()<<std::endl;
        sensor_msgs::PointCloud2 pointcloud_pub;
        pcl::toROSMsg(*cloud_ros, pointcloud_pub);
        //eric_wang:set the frame_id of the filtered PointCloud2;
        pointcloud_pub.header.frame_id = "/camera_frame_optical";
        //pointcloud_pub.header.stamp = ros::Time::now();
        cloud_pub.publish(pointcloud_pub);

    }


private:

    ros::Subscriber cloud_sub;
    ros::Publisher cloud_pub;
    ros::NodeHandle nh_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "cloud_filter_VoxelGrid");
    pcl_filter pcl_filter_o;

    ROS_INFO("working");
    ros:: Rate loop_rate(100);
    ros::spin();



}


