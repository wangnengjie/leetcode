package mergeKLists

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	l := len(lists)
	if l == 0 {
		return nil
	}
	for l > 1 {
		flag := l % 2
		l /= 2
		for i := 0; i < l; i++ {
			lists[i] = mergeTwoLists(lists[i], lists[i+l])
		}
		if flag == 1 {
			lists[l] = lists[2*l]
		}
		l += flag
	}
	return lists[0]
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	l3 := ListNode{0, nil}
	t := &l3
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			t.Next = l1
			l1 = l1.Next
		} else {
			t.Next = l2
			l2 = l2.Next
		}
		t = t.Next
	}
	if l1 == nil {
		t.Next = l2
	} else {
		t.Next = l1
	}
	return l3.Next
}
