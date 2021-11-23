#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <utility>
#include <iostream>

using std::swap;

template <typename Iter>
void BuildHeap(Iter beg, Iter end);
template <typename Iter>
auto DeleteMax(Iter beg, Iter end) -> decltype(*beg + 0);


template <typename Iter>
void HeapSort(Iter beg, Iter end)
{
	BuildHeap(beg, end); // 将输入构造成最大堆

	Iter new_end = end;
	for (int i = 0; i < end - beg; i++)
	{
		auto max_value = DeleteMax(beg, new_end); // 删除堆中的最大值
		*(--new_end) = max_value; // 将最大值插入序列尾部
	}
}


// 对输入迭代器beg和end范围内的迭代器cur进行下滤
// 使该节点满足最大堆的堆序性
template <typename Iter>
void PercolateDown(Iter beg, Iter end, Iter cur)
{
	Iter child;
	int index = cur - beg + 1; // 通过迭代器计算下标
	while (beg + (index * 2) - 1 < end)
	{
		child = beg + (index * 2) - 1;
		if ((child + 1 < end) && *(child + 1) > *child)
			child += 1; // 选出cur的孩子中值较大的那个

		if (*cur < *child) // 不满足堆序性
			swap(*cur, *child); // 交换cur和较大的孩子
		cur = child; // 继续检查cur的孩子是否满足
		index = cur - beg + 1;
	}
}


// 将输入迭代器beg和end范围内的值原地构造成为一个最大值堆
template <typename Iter>
void BuildHeap(Iter beg, Iter end)
{
	Iter it = beg + (end - beg) / 2 - 1; // 从倒数第二排最后一个节点开始

	for (; it >= beg; --it) // 向前直到根处
		PercolateDown(beg, end, it);
}


// 从最大值堆删除一个元素
template <typename Iter>
auto DeleteMax(Iter beg, Iter end) -> decltype(*beg + 0)
{
	decltype(*beg + 0) ret = *beg; // 保存最大值
	Iter new_end = end - 1; // 少了一个元素，尾部向前移动

	Iter cur = beg;
	int index = 1;
	for (; beg + (index * 2) - 1 < new_end; )
	{
		Iter child = beg + (index * 2) - 1;
		if ((child + 1 < new_end) && *(child + 1) > *child)
			child += 1; // 选出cur的孩子中值较大的那个

		if (*(child) > *new_end)
		{
			*cur = *child;
			cur = child;
			index = cur - beg + 1;
		}
		else
			break;
	}
	*cur = *new_end;

	return ret;
}

#endif
