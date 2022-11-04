#include <pybind11/pybind11.h>
#include <FastNoiseLite.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

float GetNoise2D(FastNoiseLite *_fast_noise, float a, float b) {
    return _fast_noise->GetNoise(a, b);
}

namespace py = pybind11;

PYBIND11_MODULE(fast_noise, m) {
    m.doc() = R"pbdoc(
        FastNoise Python binding
        -----------------------

        .. currentmodule:: fast_noise

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    py::class_<FastNoiseLite> fast_noise(m, "FastNoiseLite");

    fast_noise.def(py::init<int>())
        .def("SetSeed", &FastNoiseLite::SetSeed)
        .def("SetFrequency", &FastNoiseLite::SetFrequency)
        .def("SetNoiseType", &FastNoiseLite::SetNoiseType)
        .def("SetRotationType3D", &FastNoiseLite::SetRotationType3D)
        .def("SetFractalType", &FastNoiseLite::SetFractalType)
        .def("SetFractalOctaves", &FastNoiseLite::SetFractalOctaves)
        .def("SetFractalLacunarity", &FastNoiseLite::SetFractalLacunarity)
        .def("SetFractalGain", &FastNoiseLite::SetFractalGain)
        .def("SetFractalWeightedStrength", &FastNoiseLite::SetFractalWeightedStrength)
        .def("SetFractalPingPongStrength", &FastNoiseLite::SetFractalPingPongStrength)
        .def("SetCellularDistanceFunction", &FastNoiseLite::SetCellularDistanceFunction)
        .def("SetCellularReturnType", &FastNoiseLite::SetCellularReturnType)
        .def("SetCellularJitter", &FastNoiseLite::SetCellularJitter)
        .def("SetDomainWarpType", &FastNoiseLite::SetDomainWarpType)
        .def("SetDomainWarpAmp", &FastNoiseLite::SetDomainWarpAmp)
        .def("GetNoise", &GetNoise2D);
//        .def("GetNoise", py::overload_cast<double,double,double>(&FastNoiseLite::GetNoise));


//    // Enum
//    py::enum_<FastNoiseLite::CellularDistanceFunction>(fast_noise, "CellularDistanceFunction")
//        .value("Euclidean", FastNoiseLite::CellularDistanceFunction::Euclidean)
//        .value("Manhattan", FastNoiseLite::CellularDistanceFunction::Manhattan)
//        .value("Natural", FastNoiseLite::CellularDistanceFunction::Natural)
//        .export_values();
//
//    py::enum_<FastNoiseLite::CellularReturnType>(fast_noise, "CellularReturnType")
//        .value("CellValue", FastNoiseLite::CellularReturnType::CellValue)
//        .value("NoiseLookup", FastNoiseLite::CellularReturnType::NoiseLookup)
//        .value("Distance", FastNoiseLite::CellularReturnType::Distance)
//        .value("Distance2", FastNoiseLite::CellularReturnType::Distance2)
//        .value("Distance2Add", FastNoiseLite::CellularReturnType::Distance2Add)
//        .value("Distance2Sub", FastNoiseLite::CellularReturnType::Distance2Sub)
//        .value("Distance2Mul", FastNoiseLite::CellularReturnType::Distance2Mul)
//        .value("Distance2Div", FastNoiseLite::CellularReturnType::Distance2Div)
//        .export_values();
//
//    py::enum_<FastNoiseLite::DomainWarpType>(fast_noise, "DomainWarpType")
//        .value("None", FastNoiseLite::DomainWarpType::None)
//        .value("OpenSimplex2", FastNoiseLite::DomainWarpType::OpenSimplex2)
//        .value("OpenSimplex2Reduced", FastNoiseLite::DomainWarpType::OpenSimplex2Reduced)
//        .value("BasicGrid", FastNoiseLite::DomainWarpType::BasicGrid)
//        .value("BasicGridReduced", FastNoiseLite::DomainWarpType::BasicGridReduced)
//        .value("CubicGrid", FastNoiseLite::DomainWarpType::CubicGrid)
//        .value("CubicGridReduced", FastNoiseLite::DomainWarpType::CubicGridReduced)
//        .export_values();
//
//    py::enum_<FastNoiseLite::FractalType>(fast_noise, "FractalType")
//        .value("FBM", FastNoiseLite::FractalType::FBM)
//        .value("Billow", FastNoiseLite::FractalType::Billow)
//        .value("RigidMulti", FastNoiseLite::FractalType::RigidMulti)
//        .export_values();
//
//    py::enum_<FastNoiseLite::NoiseType>(fast_noise, "NoiseType")
//        .value("Value", FastNoiseLite::NoiseType::Value)
//        .value("ValueFractal", FastNoiseLite::NoiseType::ValueFractal)
//        .value("Perlin", FastNoiseLite::NoiseType::Perlin)
//        .value("PerlinFractal", FastNoiseLite::NoiseType::PerlinFractal)
//        .value("Simplex", FastNoiseLite::NoiseType::Simplex)
//        .value("SimplexFractal", FastNoiseLite::NoiseType::SimplexFractal)
//        .value("Cellular", FastNoiseLite::NoiseType::Cellular)
//        .value("WhiteNoise", FastNoiseLite::NoiseType::WhiteNoise)
//        .value("Cubic", FastNoiseLite::NoiseType::Cubic)
//        .value("CubicFractal", FastNoiseLite::NoiseType::CubicFractal)
//        .export_values();
//
//    py::enum_<FastNoiseLite::RotationType3D>(fast_noise, "RotationType3D")
//        .value("None", FastNoiseLite::RotationType3D::None)
//        .value("ImproveXYPlanes", FastNoiseLite::RotationType3D::ImproveXYPlanes)
//        .value("ImproveXZPlanes", FastNoiseLite::RotationType3D::ImproveXZPlanes)
//        .export_values();

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
