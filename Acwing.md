# 二分
二分的思想其实就是找左边的性质和右边性质的不同，能分开的就是要找的位置

## 例1

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
# 高精度加法
用字符串存储数字，用vector存储每一位数字