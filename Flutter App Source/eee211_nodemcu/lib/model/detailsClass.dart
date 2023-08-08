class Activity {
  final String permission;
  final String rfid;
  final String time;

  Activity(this.permission, this.rfid, this.time);

  // Create a factory constructor to parse JSON data
  factory Activity.fromJson(String id, String perm, String time) {
    return Activity(
      perm,
      id,
      time,
    );
  }
}
