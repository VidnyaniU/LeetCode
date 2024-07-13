import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class robotCollisions {

    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Integer[] indices = new Integer[n];
        List<Integer> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, (lhs, rhs) -> Integer.compare(positions[lhs], positions[rhs]));

        for (int currInd : indices) {

            // add rt moving robots to the stack
            if (directions.charAt(currInd) == 'R')
                stack.push(currInd);
            else {
                while (!stack.isEmpty() && healths[currInd] > 0) {

                    // pop the top robot from the stack for collision check
                    int topIndex = stack.pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currInd]) {
                        // current robots is destroyed top robot survives
                        healths[currInd] = 0;
                        healths[topIndex] -= 1;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currInd]) {
                        // current robots survives top robot is destroyed
                        healths[currInd] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // both robots are destroyed
                        healths[currInd] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // collect remaining robots
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                result.add(healths[i]);
        }

        return result;
    }

}