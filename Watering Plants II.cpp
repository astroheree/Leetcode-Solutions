class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int waterA = capacityA, waterB = capacityB, s = 0, e = plants.size() - 1, count = 0;
        while(s<e)
        {
            if(waterA < plants[s])
            {
                waterA = capacityA;
                count++;
            }
            waterA -= plants[s++];
            if(waterB < plants[e])
            {
                waterB = capacityB;
                count++;
            }
            waterB -= plants[e--];
        } 
        if(s==e)
        {
            int maxWater =0;
            if(waterA >= waterB) maxWater = waterA;
            else maxWater = waterB;
            if(maxWater < plants[s]) count++;
        }        
        return count;
    }
};
