from setuptools import setup

package_name = 'gazebo_map'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dongdongo',
    maintainer_email='tjehdghks4356@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
        'launch.frontend.launch_description_sources': [
            'launch_description=gazebo_map:generate_launch_description',
        ],
    },
)
