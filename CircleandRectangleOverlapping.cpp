class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Calculate the closest point to the circle within the rectangle
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate the distance between the circle's center and the closest point in the rectangle
        double distance = sqrt((closestX - xCenter) * (closestX - xCenter) +
                                     (closestY - yCenter) * (closestY - yCenter));

        // Check if the distance is less than or equal to the radius
        return distance <= radius;
    }
};
