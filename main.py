from subprocess import Popen


eicar_prefix = b'X5O!P%@AP[4\PZX54(P^)7CC)7}'
eicar_string = b'$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$'
eicar_suffix = b'H+H*'


def drop_eicar(filepath):
    print("Hello World. Dropping 'evil' executable now.")
    with open(filepath, "+wb") as f:
        f.write(eicar_prefix)
        f.write(eicar_string)
        f.write(eicar_suffix)


def run_eicar(filepath):
    print("Running 'evil' executable now.")
    Popen(filepath)


def main():
    filepath = "eicar.exe"
    drop_eicar(filepath)
    run_eicar(filepath)


if __name__ == "__main__":
    main()
