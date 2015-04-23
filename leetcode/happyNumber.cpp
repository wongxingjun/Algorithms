class Solution {
	public:
		bool isHappy(int n) {
			unordered_map<int,int> temp;
			int sum=n;
			while(sum!=1)
			{
				sum=0;
				while(n!=0)
				{
					sum+=(n%10)*(n%10);
					n/=10;
				}
				n=sum;
				if(temp.find(sum)!=temp.end())
					return false;
				temp[n]=1;
			}
			return true;
		}
};
