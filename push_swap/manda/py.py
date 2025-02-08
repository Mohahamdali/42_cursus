import random
import os
import subprocess

def generate_unique_args():
    return random.sample(range(100000001), 500)

while True:
    args = generate_unique_args()
    command = f"./push_swap {' '.join(map(str, args))}"
    result = subprocess.run(command, shell=True, capture_output=True, text=True)

    # Sauvegarde le résultat dans un fichier temporaire
    with open("temp_result.txt", "w") as temp_file:
        temp_file.write(result.stdout)

    # Vérifie le nombre de lignes
    line_count = int(subprocess.run("wc -l < temp_result.txt", shell=True, capture_output=True, text=True).stdout.strip())
    if line_count > 5500:
        print("KO")
        with open("arguments_ko.txt", "a") as log_file:
            log_file.write(' '.join(map(str, args)) + "\n")
    else:
        print("OK")