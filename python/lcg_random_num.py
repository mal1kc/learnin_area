# Linear Congruential Generator
import time

a = 9820381
c = 139281034
m = 3140985026

Number = float | int


# Function to generate random numbers using LCG
def lcg_rand(seed: Number):
    # Update the seed and return the new random number
    seed = (a * seed + c) % m
    return seed


# Function to generate a specified number of random numbers within a range
def generate_random_numbers(
    count: int, seed: Number, min_value: int, max_value: int
) -> list[Number]:
    random_numbers = []
    for _ in range(count):
        seed = lcg_rand(seed)
        # Scale the random number to the range [min_value, max_value]
        scaled_value = min_value + (seed / (m - 1)) * (max_value - min_value)
        random_numbers.append(scaled_value)
    return random_numbers


# Main function to test performance
def test_performance(num_samples: int, min_value: int, max_value: int) -> None:
    seed = 70 - 1  # Initial seed value
    # Measure time taken to generate random numbers
    start_time = time.time()
    rand_nums = generate_random_numbers(num_samples, seed, min_value, max_value)
    end_time = time.time()

    # Calculate elapsed time
    elapsed_time = end_time - start_time
    print(
        f"Time taken to generate {num_samples} random numbers: {elapsed_time:.6f} seconds"
    )
    if num_samples <= 10:
        print("here rand_nums: ", " ".join(f"{i:.2}" for i in rand_nums))


# Number of random numbers to generate
num_samples = 10000  # Change this value for different tests

# Run the performance test
if __name__ == "__main__":
    test_performance(num_samples, 10, 2000)
