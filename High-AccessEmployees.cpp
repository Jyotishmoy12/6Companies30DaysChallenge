class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    // create a map to store acces times for each employee
    map<string, vector<int>>when; // key -> name of the employee value--> acces_time of the meploye
    for(auto v:access_times){
        string a=v[0]; // key i.e name of the employee
        string b=v[1]; //  value--> acces time of the employee
        when[a].push_back(stoi(b)); // created the map
        // now it will look like this-->
    //  [["a", 549],
    //  ["b",  457],
    //  ["a",  532],
    //  ["a",  621],
    //  ["b",  540]]

    }
    // creating a vector to store the high access employees
    vector<string>res;
    // now iterate the map and check for the employee
    for(auto &[x, lst]:when){
      // sort acces time for the employes--> so now-->[457, 532, 540, 549, 621]
      sort(lst.begin(), lst.end());
      // get the number of access time for current employee
      int k=lst.size(); // so k->5
      // flag to indicate if the employee is high access employe or not
      bool flag=false;
      // check for consecutive access within a 100-minute window
      for(int i=0;i+3<=k;++i)
          // checking for this window-->(457,532, 540)// it's in the 100 minute window
          flag |=lst[i+2]<lst[i]+100; // | means bitwise OR // i=0--> 540<457+100=557 // so in 100 minute window
          if(flag==true) res.push_back(x); // push the employee name
      
    }
    return res;  
    }
};

//Input: access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]

// // Map creation
// when:
// a: [549, 532, 621]
// b: [457, 540]

// // Iterate over the map
// For employee "a":
//   Sort access times: [532, 549, 621]
//   k = 3
//   flag = false
  
//   // Check consecutive access within a 100-minute window
//   i=0: 532 < 532 + 100 -> flag |= true (flag becomes true)
//     res = ["a"]

//   i=1: (skipped because k-3 is 3)
  
// For employee "b":
//   Sort access times: [457, 540]
//   k = 2
//   flag = false
  
//   // Check consecutive access within a 100-minute window
//   i=0: (skipped because k-3 is 1)
  
// // Final result: ["a"]


// class Solution {
// public:
//     vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
//         int n = arr.size();
//         unordered_map<string,vector<int>> mp;
        
//         for(auto it : arr)
//             mp[it[0]].push_back(stoi(it[1]));
             
//         vector<string> ans;
        
//         for(auto it : mp)
//         {
//             sort(it.second.begin(),it.second.end());
//             int sz = it.second.size();
//             bool flag = false;
//             for(int i=0;i+3<=sz;i++)
//             {
//                 if(it.second[i+2] < it.second[i] + 100)
//                     flag = true;
//             }
//             if(flag)
//                 ans.push_back(it.first);
//         }
//         return ans;
//     }
// };
