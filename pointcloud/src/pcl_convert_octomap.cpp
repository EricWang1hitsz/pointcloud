////ros
//#include <ros/ros.h>
//#include <iostream>
//#include <assert.h>

////pcl
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>

////octomap
//#include <octomap/octomap.h>
//#include <octomap_msgs/conversions.h>
//#include <octomap_msgs/Octomap.h>
//using namespace std;

//int main( int argc, char** argv )
//{
//    if (argc != 3)
//    {
//        cout<<"Usage: pcd2octomap <input_file> <output_file>"<<endl;
//        return -1;
//    }

//    string output_file = argv[2];
//    pcl::PointCloud<pcl::PointXYZRGBA> cloud;
//    pcl::io::loadPCDFile<pcl::PointXYZRGBA> ( "/home/hit/catkin_ws_eric/src/pointcloud/src/happy.pcd", cloud );

//    cout<<"point cloud loaded, piont size = "<<cloud.points.size()<<endl;

//    //声明octomap变量
//    cout<<"copy data into octomap..."<<endl;
//    // 创建八叉树对象，参数为分辨率，这里设成了0.05
//    octomap::OcTree tree( 0.05 );

//    for (auto p : cloud.points)
//    {
//        // 将点云里的点插入到octomap中
//        tree.updateNode( octomap::point3d(p.x, p.y, p.z), true );
//    }

//    // 更新octomap
//    tree.updateInnerOccupancy();
//    // 存储octomap
//    //tree.writeBinary( output_file );
//    tree.write(output_file);
//    cout<<"done."<<endl;

//    octomap_msgs::Octomap octomap_msgs;
//    //octomap_msgs::binaryMapToMsg(output_file, octomap_msgs);
//    octomap_msgs::fullMapToMsg(output_file, octomap_msgs);
//    ros::NodeHandle nh_;
//    ros::Publisher octomap_pub = nh_.advertise<octomap_msgs::Octomap>("/octomap_binary", 1);

//    ros::Rate loop_rate(10);

//    return 0;
//}
