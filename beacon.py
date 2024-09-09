from urllib.request import urlopen


def main():
    urls = [
        "https://www.google.com",
        "https://www.facebook.com",
        "https://www.x.com",
        "https://www.github.com"
    ]
    for url in urls:
        with urlopen(url) as resp:
            print(f"{url} returned {resp.getcode()}")


if __name__ == "__main__":
    main()
