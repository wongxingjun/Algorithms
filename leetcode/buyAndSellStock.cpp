class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if(prices.size()<=1)
				return 0;
			else if(prices.size()==2)
				return (prices[1]-prices[0])>0?(prices[1]-prices[0]):0;
			int i=0,j=prices.size()-1;
			int maxPro=prices[prices.size()-1]-prices[0];
			while(i!=j)
			{
				if(prices[j-1]-prices[i]>maxPro)
				{
					maxPro=prices[j-1]-prices[i];
					j--;
				}
				else if(prices[j]-prices[i+1]>maxPro)
				{
					maxPro=prices[j]-prices[i+1];
					i++;
				}
				i++;
				j--;
			}
			return maxPro;   
		}
};
