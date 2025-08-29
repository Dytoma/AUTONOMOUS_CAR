# 🚗 Autonomous Car Simulation in C with CoppeliaSim

_A simulation of an autonomous vehicle built in **C**, using the **CoppeliaSim** robotics platform._

---

## 📌 Overview

This project demonstrates the control and behavior of an **autonomous car** inside the **CoppeliaSim simulator**.  
It was designed to showcase skills in:

- **C programming** for robotics and real-time systems
- **Simulation environments** with CoppeliaSim
- **Autonomous navigation algorithms**
- **Sensor integration & decision-making logic**

---

## 🤖 Features

- 🚙 **Autonomous vehicle simulation** in CoppeliaSim
- 📡 **Virtual sensors** (proximity, lidar, or vision sensors) for obstacle detection
- 🧭 **Navigation logic**: path following and obstacle avoidance
- 🛠️ Modular C code for car control and environment interaction
- 📊 Configurable parameters for testing different driving scenarios

---

## 🛠️ Tech Stack

- **Language:** C
- **Simulator:** [CoppeliaSim](https://www.coppeliarobotics.com/)
- **APIs:** Remote API / Simulation control with C bindings
- **Build Tool:** Makefile

---

## 🎥 Demo

To launch the demonstration on your compute, you need to download the **CoppeliaSim** simulator on their official website  
and run it on your computer. There are some tracks included in this repository under ``/n4s_package/scene/*.ttf``. These are the steps to successfully run the simulation:
- Load a scene in the simulator
- Run ``make`` to build the executable
- Run the ``pipes.sh`` file on another terminal to ensure communication between the ai and the coppeliaSim simulator
- Lastly run the executable with the following command at the root of you folder ```./ai```

You might need to add executable permission to the script files, simply execute the following command:
```shell
chmod +x your_file
```

---

## 📖 Key Takeaways

- Implemented **real-time control loops** in C
- Designed **decision-making logic** for autonomous navigation
- Integrated **CoppeliaSim’s remote API** with custom C code
- Gained hands-on experience in **robotics simulation & embedded systems concepts**

---

## 👤 Author

**Dytoma Batogouma**  
💼 [LinkedIn](https://www.linkedin.com/in/dytoma-batogouma-6aa946235/) • 🌐 [Portfolio](https://dytoma.fr) • 📧 dytomaomar@gmail.com 
