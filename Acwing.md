# 目录

- [二分](#section1)
- [高精度](#section2)
- [前缀和](#section3)
- [双指针](#section4)
- [位运算](#section5)
- [离散化处理](#section6)
- [区间合并](#section7)


## 二分 <a name="section1"></a>

二分的思想其实就是找左边的性质和右边性质的不同，能分开的就是要找的位置

### 例1

1 2 2 3 3 4

那么要找第一次出现三的位置，就是左边都小于三，右边都大于等于三

要找最后一次出现三的位置，就是左边都小于等于三，右边都大于三

```c++
int l=0,r=n-1;
while(l<r){
  int mid=l+r>>1;//这里mid向下取整
  if(a[mid]>=3) r=mid;//右边界往左移时，不会陷入循环
  else l=mid+1;
}
l=0,r=n-1
while(l<r){
  int mid=l+r>+1>1;//这里mid向上取整
  if(a[mid]<=3) l=mid;//左边界往右移，如果mid是像下取整的时候，只有两个数时，会陷入死循环，所以mid要向上取整
  else r=mid-1;
}
```

## 高精度 <a name="section2"></a>

用字符串存储数字，再用容器存每一个数（记得要-‘0’！！！！）

## 前缀和 <a name="section3"></a>

### 主要运用
当需要对一段区域的数进行改变时，把O（n）的时间复杂度改为O（1）
### 重点：
前缀和与差分互逆运算；

画图去想，最直观；

已知数组，要求差分，只要进行如下插入操作
```c++
Insert<diff,i,i,elem[i]>//相当于原始数组都为零，将数组插入时diff数组需要的值；

//思想：在a[l,r]上的数都加一个elem，则只要在diff[l]+=elem;diff[r+1]-=elem;
//然后又前缀和与差分互逆运算；即a[i]=b[i]+=b[i-1]，所以可以更新数组
void Insert(vector<int > &diff,int l ,int r,int elem){
    diff[l]+=elem;
    diff[r+1]-=elem;
}
```
### 注意
边界条件，数组边界容易越界，所以需要加一个”0的矩形框“
```c++
vector<vector<int> >a(n+2,vector<int>(m+2));//多声明两行两列
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];//只用中间的矩形
    }
```




## 双指针 <a name="section4"></a>

### 主要运用 
将O（n^2）优化成O（n）
### 模板
```c++
for(int i=0;i<n;i++){
  while(j<i&&check(j))j++

}
```
### 注意
分清楚if while for的区别！

## 位运算 <a name="section5"></a>
#### lowbit() 
```c++
int lowbit(int x){
  return x&-x;
}
```

## 离散化处理 <a name="section6"></a>
### 主要目的
把分布疏松的数据映射到排列紧凑的数组。

```c++
    //use_index 获得使用了的数组下标(稀疏)
    sort(map_index.begin(),map_index.end());
    map_index.erase(unique(map_index.begin(),map_index.end()),map_index.end()); ////去重，把下标进一步映射，紧凑
```

## 区间合并 <a name="section7"></a>
### 重点
一个区间重要的两个因素左端点，右端点，即可用来表示一个区间。

