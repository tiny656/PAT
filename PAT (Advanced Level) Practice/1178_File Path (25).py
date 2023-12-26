# Dictionary to store child -> parent relationships
parent_dict = {}


def build_tree(lines):
    # Stack to keep track of the current path
    stack = []
    # Parse the tree structure
    for line in lines:
        # Count the leading spaces to determine the depth
        depth = len(line) - len(line.lstrip(" "))
        # Get the ID without leading spaces
        id = line.strip()
        # If the stack is longer than the depth, pop elements
        while len(stack) > depth:
            stack.pop()
        # If the stack is not empty, the last element is the parent
        if stack:
            parent_dict[id] = stack[-1]
        # Push the current id onto the stack
        stack.append(id)


# Function to trace back the path from a node to the root
def get_path(id):
    path = []
    while id in parent_dict:
        path.append(id)
        id = parent_dict[id]
    path.append("0000")  # Root ID
    return "->".join(reversed(path))


n = int(input())
lines = []
for i in range(n):
    lines.append(input())
build_tree(lines)

queries = input().split()[1:]
# Process the queries
for query in queries:
    # Check if the ID exists in the tree
    if query in parent_dict or query == "0000":
        print(get_path(query))
    else:
        print(f"Error: {query} is not found.")
