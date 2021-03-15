import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation
import matplotlib.dates as md
from matplotlib import style
import tkinter as tk
from tkinter import ttk
import urllib
import json
import pandas as pd
import numpy as np
from pandas.plotting import register_matplotlib_converters
register_matplotlib_converters()
import socket
import pickle
import datetime
import matplotlib.pyplot as plt

LARGE_FONT= ("Verdana", 12)
NORM_FONT= ("Verdana", 10)
SMALL_FONT= ("Verdana", 8)
style.use("ggplot")

f = Figure(figsize=(10,6), dpi=100)
a = f.add_subplot(111)

HEADERSIZE = 10
port = 5000
tempList = []
timeList = []
title = "Temperaturas registradas"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("192.168.43.126", port))

def animate(i):
    full_msg = b''
    new_msg = True
    msg = s.recv(120)
    if new_msg:
        msglen = int(msg[:HEADERSIZE])
        new_msg = False

    full_msg += msg

    if len(full_msg)-HEADERSIZE == msglen:
        new_msg = True
        mensaje = pickle.loads(full_msg[HEADERSIZE:])
        full_msg = b""
        temp = mensaje['temp']
        temp = float(temp)
        time = mensaje['time']
        time = datetime.datetime.strptime(time, "%a %b %d %H:%M:%S %Y")
        tempList.append(temp)
        timeList.append(time)
        a.clear()
        a.plot(timeList,tempList,"#00A3E0",label="ºC")
        time = md.DateFormatter("%H:%M:%S")
        a.legend(bbox_to_anchor=(0, 1.02, 1, .102), loc=3, ncol=2, borderaxespad=0)
        a.set(xlabel="Tiempo", ylabel="Temperatura",title=title)

def tutorial():

    def page2():
        tut.destroy()
        tut2 = tk.Tk()

        def page3():
            tut2.destroy()
            tut3 = tk.Tk()

            tut3.wm_title("Part 3!")

            label = ttk.Label(tut3, text="", font=NORM_FONT)
            label.pack(side="top", fill="x", pady=10)
            B1 = ttk.Button(tut3, text="Done!", command= tut3.destroy)
            B1.pack()
            tut3.mainloop()

        tut2.wm_title("Part 2!")
        label = ttk.Label(tut2, text="""BIENVENIDO AL ASIST
                                        use at your own risk. There is no promise
                                        of warranty.""", font=NORM_FONT)
        label.pack(side="top", fill="x", pady=10)
        B1 = ttk.Button(tut2, text="Next", command= page3)
        B1.pack()
        tut2.mainloop()

    tut = tk.Tk()
    tut.wm_title("Tutorial")
    label = ttk.Label(tut, text="What do you need help with?", font=NORM_FONT)
    label.pack(side="top", fill="x", pady=10)

    B1 = ttk.Button(tut, text = "Overview of the application", command=page2)
    B1.pack()

    B2 = ttk.Button(tut, text = "¿Como conectarme a un puerto en especifico?", command=lambda:popupmsg("Haga click TCP-IP -> Setup e introduzca el numero de puerto"))
    B2.pack()

    B3 = ttk.Button(tut, text = "¿Como exportar un grafico?", command=lambda:popupmsg("Haga click Save Plot -> Save e introduzca el nombre y la extension"))
    B3.pack()

    tut.mainloop()

def popupmsg(msg):
    popup = tk.Tk()
    def leavemini():
        popup.destroy()

    popup.wm_title("!")
    label = ttk.Label(popup, text = msg, font=NORM_FONT)
    label.pack(side="top",fill="x",pady=10)
    B1 = ttk.Button(popup,text="Okay",command=leavemini)
    B1.pack()
    popup.mainloop()

def SetupPort():
    global port

    ST = tk.Tk()
    ST.wm_title("Port?")
    label = ttk.Label(ST, text = "Introduce the port number, please.")
    label.pack(side="top", fill="x", pady=10)

    e = ttk.Entry(ST)
    e.insert(0,1234)
    e.pack()
    e.focus_set()
    def callback():
            global port
            port = (e.get())
            group = []
            group.append("TCP-IP")
            group.append(port)
            print("Set mode and port to",group)
            ST.destroy()

    b = ttk.Button(ST, text="Submit", width=10, command=callback)
    b.pack()
    tk.mainloop()

def Save():
    global port

    ST = tk.Tk()
    ST.wm_title("Save PLot")
    label = ttk.Label(ST, text = "Introduce the file name and extension, please.")
    label.pack(side="top", fill="x", pady=10)

    e = ttk.Entry(ST)
    e.pack()
    e.focus_set()
    def callback():
            global port
            name = (e.get())
            plt.plot(timeList,tempList,"#00A3E0",label="ºC")
            time = md.DateFormatter("%H:%M:%S")
            plt.legend(bbox_to_anchor=(0, 1.02, 1, .102), loc=3, ncol=2, borderaxespad=0)
            plt.savefig(name,transparent=True, bbox_inches = "tight")
            ST.destroy()

    b = ttk.Button(ST, text="Submit", width=10, command=callback)
    b.pack()
    tk.mainloop()

class TempGraphApp(tk.Tk):

    def __init__(self, *args, **kwargs):

        tk.Tk.__init__(self, *args, **kwargs)

        #tk.Tk.iconbitmap(self, default="clienticon.ico")
        tk.Tk.wm_title(self, "Lector Temperatura")


        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        menubar = tk.Menu(container)

        filemenu = tk.Menu(menubar, tearoff=0)
        filemenu.add_command(label="Save settings",
                             command = lambda: popupmsg("Not supported just yet!"))
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=quit)
        menubar.add_cascade(label="File", menu=filemenu)

        portChoice = tk.Menu(menubar, tearoff=1)
        portChoice.add_command(label="Setup",
                                   command=lambda: SetupPort())
        menubar.add_cascade(label="TCP-IP", menu=portChoice)

        saveFigure = tk.Menu(menubar, tearoff=0)
        saveFigure.add_command(label="Save",
                                   command=lambda: Save())
        menubar.add_cascade(label="Save Plot", menu=saveFigure)

        helpmenu = tk.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="Tutorial", command=tutorial)
        menubar.add_cascade(label="Help", menu=helpmenu)

        tk.Tk.config(self, menu=menubar)
        self.frames = {}

        for F in (StartPage, Graph_Page):

            frame = F(container, self)

            self.frames[F] = frame

            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()

class StartPage(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text=("""Graficador de temperatura"""), font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Aceptar",
                            command=lambda: controller.show_frame(Graph_Page))
        button1.pack()

        button2 = ttk.Button(self, text="Salir",
                            command=quit)
        button2.pack()

class Graph_Page(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="GRAFICO DE TEMPERATURA", font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        canvas = FigureCanvasTkAgg(f, self)
        canvas.draw()
        canvas.get_tk_widget().pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

app = TempGraphApp()
app.geometry("1280x720")
ani = animation.FuncAnimation(f, animate, interval=5000)
app.mainloop()
