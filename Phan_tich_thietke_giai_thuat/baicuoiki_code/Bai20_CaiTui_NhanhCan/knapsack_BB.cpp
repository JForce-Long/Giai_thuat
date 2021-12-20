#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
struct item
{
    float w;     // weight
    float v;     // value
    float unit;  // unit price = v/w
    int num = 0; // 0 or 1
};

int W,                                        // khối lượng tối đa của túi
    N;                                        // số item
item Items[MAX + 1];                          // mảng lưu các vật
int d[MAX + 1] = {0};                         // mảng lưu vết tạm thời các đồ vật có được thêm hay không
float curr_val = 0,                           // current total value
    curr_weight = 0;                          // current total weight
float maxVal = 0, totalWeight = 0, total = 0; // giá trị tối ưu
float g;                                      // cận trên

void Input()
{
    ifstream infile;
    infile.open("CaiTui1.txt");
    infile >> W >> N;
    cout << "n=" << N << " w=" << W << "\n";
    for (int i = 1; i <= N; i++)
    {
        infile >> Items[i].w >> Items[i].v;
        Items[i].unit = Items[i].v / Items[i].w;

        cout << "#" << i << ": " << Items[i].w << " " << Items[i].v << "\n";
    }
    infile.close();
}

/* Sắp xếp các đồ vật theo thứ tự không giảm về tỷ số (unit price) */
void swap(item *a, item *b)
{
    item t = *a;
    *a = *b;
    *b = t;
}
void qSort(int left, int right)
{
    int i = left, j = right;
    item pivot = Items[(left + right) / 2]; // chọn pivot là giá trị ở giữa

    /* partition */
    while (i <= j)
    {
        while (Items[i].unit < pivot.unit)
            i++;
        while (Items[j].unit > pivot.unit)
            j--;

        if (i <= j)
        {
            swap(&Items[i], &Items[j]);
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        qSort(left, j);
    if (i < right)
        qSort(i, right);
}

/* Kiểm tra và cập nhật giá trị tối ưu */
void test()
{
    if (curr_val > maxVal)
    {
        maxVal = curr_val;
        totalWeight = curr_weight;
        total = 0;
        for (int i = 1; i <= N; i++)
        {
            Items[i].num = d[i];
            total += d[i];
        }
    }
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    { // thử 2 trường hợp, chọn (1) hoặc không (0)
        if (curr_weight + i * Items[k].w <= W)
        {
            curr_weight += i * Items[k].w;
            curr_val += i * Items[k].v;
            d[k] = i;

            if ((k == N) && (curr_weight <= W))
            {
                test();
            }
            else
            {
                /* Khác quay lui ở đoạn này 
                 * Thay vì trực tiếp thử thêm vật k+1, 
                 * kiểm tra xem nhánh này còn khả năng cho nghiệm hay không
                 */
                float remaining_cap = W - curr_weight; // trọng lượng còn lại cho phép
                
                // cập nhật cận trên
                g = curr_val + Items[k + 1].v * remaining_cap / Items[k + 1].w;
                
                // Nếu giá trị tối ưu hiện tại chưa vượt quá cận trên thì nhánh này vẫn có khả năng cho nghiệm
                if (g > maxVal)
                {
                    Try(k + 1);
                }
            }

            curr_weight -= i * Items[k].w;
            curr_val -= i * Items[k].v;
            d[k] = 0;
        }
    }
}

void PrintResult()
{
    cout << "\nCac vat da lay: ";
    for (int i = 1; i <= N; i++)
    {
        if (Items[i].num)
        {
            cout << i << " ";
        }
    }
    cout << "\nTong so vat da lay: " << total;
    cout << "\nGia tri lon nhat co the lay: " << maxVal;
    cout << "\nKhoi luong da su dung: " << totalWeight << endl;
}

int main()
{
    Input();
    qSort(0, N - 1);
    Try(1);
    PrintResult();
}