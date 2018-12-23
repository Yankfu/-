package Yankfu;

public class bubble_sort 
{
	public static void main(String[] args) {
		int[] numbers = {2,5,3,7,6,45,24,84,634,25,45,66};
		bubbleSort bs=new bubbleSort();
		bs.bubbleSort(numbers);
		bs.print();
	}
}
class bubbleSort{
	private int[] nums;
	public void sort() {
		for(int i=0;i<nums.length;i++) {
			int temp=0;
			Boolean isfinish=true;
			for(int j=1;j<nums.length-i;j++,temp++) {
				if(nums[temp]>nums[j]) {
					change(temp,j);
					isfinish=false;
				}
			}
			if(isfinish) {
				break;
			}
		}
	}
	private void change(int i, int j) {
		// TODO Auto-generated method stub
		int num=0;
		num=nums[i];
		nums[i]=nums[j];
		nums[j]=num;
	}
	public int[] bubbleSort(int[] nums) {
		this.nums=nums;
		sort();
		return nums;
	}
	public void print() {
		for(int i=0;i<nums.length;i++) {
			System.out.print(nums[i]+" ");
		}
	}
}