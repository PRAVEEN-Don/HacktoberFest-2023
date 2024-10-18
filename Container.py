public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int maxArea = 0; // Variable to store the maximum area
        int left = 0;    // Left pointer
        int right = height.length - 1; // Right pointer

        // Loop until the two pointers meet
        while (left < right) {
            // Calculate the width and the height
            int width = right - left;
            int currentHeight = Math.min(height[left], height[right]);
            int currentArea = width * currentHeight;

            // Update the maximum area
            maxArea = Math.max(maxArea, currentArea);

            // Move the pointer for the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea; // Return the maximum area found
    }

    public static void main(String[] args) {
        ContainerWithMostWater solution = new ContainerWithMostWater();
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input
        int maxArea = solution.maxArea(height);
        System.out.println("The maximum area of water the container can hold is: " + maxArea);
    }
}
