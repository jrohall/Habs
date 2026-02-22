# Habs: A minimal habit tracker

==== BETA 1.0 ====

This app is a beta release of a minimal habit tracker that allows users to set custom habits on the pebble app, which will update the pebble application. Once the user logs a habit, the streak tab will be updated.

Please keep in mind this is a very minimal beta application and will be updated with more features and better GUI going into the future.

Feel free to visit the GitHub page to add suggestions, report bugs and more!

## Preview
Home Interface:

<img width="109" alt="Screen Shot 2023-02-24 at 3 34 33 PM" src="https://user-images.githubusercontent.com/103393035/221299217-732bdcf4-5c16-4f8a-a883-dc2151e6ee9f.png">

Habit Screen:

<img width="108" alt="Screen Shot 2023-02-24 at 3 34 05 PM" src="https://user-images.githubusercontent.com/103393035/221299283-a86a29b7-1a74-425c-b5ab-d18459942f8f.png">

Streaks Window:

<img width="108" alt="Screen Shot 2023-02-24 at 3 35 34 PM" src="https://user-images.githubusercontent.com/103393035/221299327-29baf83c-ef84-4142-a5b7-5530e22498fa.png">


## Getting Started

Access the rebble store here: https://store-beta.rebble.io/faces
Once the application is downloaded onto the watch, habits can be saved in the settings page on the pebble application.

### Developers

If you would like a copy of the code, copy the commands below:

1. Clone into the repo

```
git clone https://github.com/jrohall/pebble_habit_tracker
```

2. View the watch app from your end

```
pebble build && pebble install --emulator basalt
```

3. View the pebble app configuration

```
pebble install --emulator basalt && pebble emu-app-config
```

### Code Notes

The code in the application is very messy in the sense that I was unable to use some of the data sructures I was hoping for. I know that it is very repetitive and I hope to fix some of these issues in the future. Thanks for checking this out, from a new pebble developer!

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Pebble SDK](https://developer.rebble.io/developer.pebble.com/sdk/index.html) - The SDK used
* [Pebble-Clay](https://maven.apache.org/) - Pebble app configuration

## Contributing

Not open at the moment, coming soon!

## Authors

* **jrohall** - *Beta 1.0*
* **arenovas** 

## Acknowledgments

* Rebble - for keeping the pebble alive :)
* Pebble UI Examples - https://github.com/pebble-examples/ui-patterns
