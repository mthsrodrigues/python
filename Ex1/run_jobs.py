import subprocess
from multiprocessing import Process


def run_job(n):
    with open(f"output_{n}.txt", "w") as file:
        subprocess.run(
            ["./hello", str(n)],
            stdout=file,
            check=True,
        )


if __name__ == "__main__":
    processes = []

    for n in range(1, 11):
        process = Process(target=run_job, args=(n,))
        process.start()
        processes.append(process)

    for process in processes:
        process.join()
