from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    # Chemin du fichier de config RViz
    rviz_config_file = PathJoinSubstitution([
        FindPackageShare("tekbot_navigation"),
        "rviz",
        "tekbot_config_map_b2ms.rviz"
    ])

    # Chemin du fichier de paramètres SLAM Toolbox
    my_slam_params_file = PathJoinSubstitution([
        FindPackageShare("tekbot_navigation"),
        "config",
        "mapper_params_online_async.yaml"
    ])

    # Lancement de SLAM Toolbox (online async) avec les bons paramètres
    slam_toolbox_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare("slam_toolbox"),
                "launch",
                "online_async_launch.py"
            ])
        ]),
        launch_arguments={
            'use_sim_time': 'true',
            'slam_params_file': my_slam_params_file
        }.items()
    )

    # Lancement de RViz
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        parameters=[{'use_sim_time': True}],
        arguments=['-d', rviz_config_file]
    )

    return LaunchDescription([
        slam_toolbox_launch,
        rviz_node
    ])
