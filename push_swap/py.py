import random
import subprocess

def generate_unique_args():
    return random.sample(range(7657751), 500)

while True:
    args = generate_unique_args()
    command = f"./push_swap {' '.join(map(str, args))}"
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    
    output = result.stdout.strip()
    line_count = len(output.split('\n')) if output else 0

    if line_count > 5500:
        print("KO")
        with open("arguments_ko.txt", "a") as log_file:
            log_file.write(f"Les arguments : {' '.join(map(str, args))}\nNombre de lignes : {line_count}\n\n")
    else:
        print("OK")