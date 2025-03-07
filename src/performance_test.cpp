#include &lt;Arduino.h&gt;
#include &lt;TeensyThreads.h&gt;
#include &lt;IntervalTimer.h&gt;

IntervalTimer timer;
volatile unsigned long thread_count = 0;
volatile unsigned long timer_count = 0;

void timerCallback() {
  timer_count++;
}

void threadFunction() {
  while(1) {
    thread_count++;
    threads.yield();
  }
}

void setup() {
  Serial.begin(9600);
  
  // Start IntervalTimer
  timer.begin(timerCallback, 1000);  // 1ms interval
  
  // Start TeensyThread
  threads.addThread(threadFunction);
}

void loop() {
  static unsigned long last_print = millis();
  
  if (millis() - last_print >= 1000) {
    Serial.print("Thread count: ");
    Serial.print(thread_count);
    Serial.print("  Timer count: ");
    Serial.println(timer_count);
    
    thread_count = 0;
    timer_count = 0;
    last_print = millis();
  }
}