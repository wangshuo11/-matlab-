# -matlab-
使用matlab求出points数据，在使用opencv fitellipse求出椭圆参数，由于直接使用matlab参数求出来的 fitellipse参数又问题，所以换成opencv求参数，之所以先在matlab中求出数据点，是因为需要matlab中那种三个阈值过滤的数据点，所以我们使用matlab先求出各个雨区的轮廓点数据集，然后在使用opencv,fitellipse 函数 求出各个雨区椭圆拟合参数，此处是结合原来的平均降雨量和ID,和opencv fitellipse 跑出来的数据一起生成新的精准雨区数据
