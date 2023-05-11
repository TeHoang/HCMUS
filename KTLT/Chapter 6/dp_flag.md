# Flag
Lời giải cho bài quy hoạch động của thầy Tùng môn KTLT (11/5/2023)

## Description
Cho một lá cờ có $N (N\geq3)$  sọc, gồm có $3$ màu: xanh, trắng, đỏ. Hỏi có bao nhiêu cách để tạo ra lá cờ sao cho: 

    Lá cờ phải có đủ cả 3 màu 
    Sọc màu trắng phải nằm giữa sọc màu xanh và đỏ

## Sample

    Input: 5
    Output: 8

Giải thích: có thể tạo ra 8 lá cờ gồm 5 sọc thỏa mãn điều kiện đề bài:

    XTĐXĐ   ĐTXTĐ   ĐTXĐX   XTĐTX
    XĐXTĐ   XĐXTĐ   ĐXĐTX   ĐXĐTX

## Solution

Ta tiến hành phân tích bài toán:

 
Ta đặt $dp_{ij}$ là số cách để tạo ra lá cờ có $i$ sọc và màu của sọc thứ $i$ là $j$ sao cho thỏa điều kiện đề bài

$j = \{0,1,2\}$ lần lượt tương ứng với màu xanh, đỏ và trắng

Ví dụ: xét $dp_{40}$ là số cách để tạo ra lá cờ có $4$ sọc sao cho sọc thứ $4$ có màu xanh thỏa điều kiện đề bài

Các lá cờ ta có thể tạo ra là

    XTĐX    XĐTX 

Vậy $dp_{40}=2$

Đáp án bài toán của ta sẽ là 

$$\sum_{j=0}^2 dp_{Nj}$$

Tức là số cách tạo ra lá cờ $N$ sọc sao cho sọc thứ $N$ màu xanh + đỏ + trắng

Tuy nhiên nếu ta phân tích thêm một chút ta sẽ thấy 
$dp_{i2}=0$ $(0\leq i \leq N)$ vì sọc trắng không thể là sọc đứng cuối cùng

Trường hợp cơ bản $(N=3)$

$dp_{30}=1$ (ĐTX)

$dp_{31}=1$ (XTĐ)

Lưu ý rằng khi $N\leq2$ thì $dp_{Nj}=0$ $\forall j \in \{0,1,2\}$ vì không thể tạo ra lá cờ với đủ 3 màu chỉ với 2 sọc trở xuống

Khi xét tới sọc thứ $i$ sẽ có hai khả năng xảy ra 

Khả năng thứ 1:

Sọc thứ $i$ màu xanh, tức là ta đang đi tìm kết quả cho $dp_{i0}$

Lúc này để cho lá cờ của chúng ta thỏa mãn được yêu cầu đề bài thì sọc thứ $i-1$ không thể là màu xanh mà chỉ có thể là màu đỏ hoặc trắng

Trường hợp màu của sọc thứ $i-1$ là đỏ thì số cách để tạo ra lá cờ có $i-1$ sọc và màu của sọc cuối cùng màu đỏ chính là $dp_{i-1,1}$

Trường hợp màu của sọc thứ $i-1$ là màu trắng thì sẽ xảy ra 2 trường hợp con 

Trường hợp con đầu tiên đó là lá cờ có $i-2$ sọc đầu tiên có màu trắng, lúc này ta chỉ cần xét tới màu của sọc thứ $i-2$, vì ta cần màu trắng nằm giữa xanh và đỏ mà màu của sọc thứ $i$ là màu xanh, do đó sọc thứ $i-2$ phải là màu đó, vậy số cách đó là $dp_{i-2,1}$

Trường hợp con còn lại là khi lá cờ có $i-2$ đầu tiên không hề tồn tại sọc màu trắng mà chỉ có xanh hoặc đỏ, nếu là vậy thì các sọc xanh và đỏ đó phải xen kẽ nhau (ví dụ XĐXĐX), ta thấy chỉ tồn tại 2 chuỗi như vậy (chuỗi X bắt đầu trước và chuỗi Đ bắt đầu trước), và do ta cần màu thứ $i-2$ là màu đỏ, ta chỉ được phép $+1$

Vậy ta đã có công thức cho $dp_{i0}$

$$dp_{i0}=dp_{i-1,1}+dp_{i-2,1}+1$$

Khả năng thứ 2:

Sọc thứ $i$ màu đỏ, tức là ta đang đi tìm kết quả cho $dp_{i1}$

Suy luận tương tự như khả năng thứ nhất ta sẽ có công thức

$$dp_{i1}=dp_{i-1,0}+dp_{i-2,0}+1$$

## Script

```c++
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 60;

int n;
vector <vector<ll>> dp(MAXN,vector<ll>(MAXN));

int main()
{
    cin >> n;
    dp[3][0] = 1, dp[3][1] = 1;
    for(int i=4;i<=n;++i)
    {
        dp[i][0] = dp[i-1][1] + dp[i-2][1] + 1;
        dp[i][1] = dp[i-1][0] + dp[i-2][0] + 1;
    }
    cout << dp[n][0] + dp[n][1] << '\n';
}
```