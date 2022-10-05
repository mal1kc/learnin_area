class Company {
  final String name;
  final int? foundationYear;
  final String country;

  late final List<double> geoCode;
  late final String _id;

  // Company(this.name, this.foundationYear,
  //     {this.geoCode = const [43.7001100, -79.4163], this.country = 'CA'});
  Company(this.name, this.foundationYear,
      {this.geoCode = const [43.7001100, -79.4163], this.country = 'CA'}) {
      
    _id = '${this.country}_${(this.foundationYear ?? 00)}_${name}';
  }

  bool get isEmptyID => _id.isEmpty;
}
