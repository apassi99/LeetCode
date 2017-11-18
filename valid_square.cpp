class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);

        map<double, bool, cmp_double> distanceSeen;

        for (int i = 0; i < 4; i++) {
            int numEqual = 0;
            vector<int> pointA = points[i];

            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    vector<int> pointB = points[j];

                    if ( (pointB[1] == pointA[1]) && (pointB[0] == pointA[0])) {
                        return false;
                    }

                    double distance = sqrt(pow(pointB[1] - pointA[1], 2) + pow(pointB[0] - pointA[0], 2));
                    map<double,bool>::iterator it = distanceSeen.find(distance);

                    if(it != distanceSeen.end()) {
                        numEqual++;
                    }

                    distanceSeen[distance] = true;
                }
            }
            
            if (i == 0 && numEqual != 1) {
                return false;
            } else if (i > 0 && numEqual != 3) {
                return false;
            }
        }

        return true;
    }

private:
    struct cmp_double : public std::binary_function<double, double, bool>
    {
        bool operator()(const double& left, const double& right) const
        {
            double epsilon = 1e-7;
            return (abs(left - right) > epsilon) && (left < right);
        }
    };
};