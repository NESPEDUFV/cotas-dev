set(base_examples
    broadcast_100
    broadcast_80
    casaInteligente_60
    broadcast_10
    broadcast_90
    casaInteligente_70_average
    broadcast_20
    casaInteligente_100
    casaInteligente_80
    broadcast_30
    casaInteligente_10
    casaInteligente_90
    broadcast_40
    casaInteligente_20
    broadcast_50
    casaInteligente_30
    broadcast_60
    casaInteligente_40
    teste
    broadcast_70
    casaInteligente_50

)

foreach(
  example
  ${base_examples}
)
  build_lib_example(
    NAME ${example}
    SOURCE_FILES ${example}.cc
    LIBRARIES_TO_LINK ${cotas-dev}
  )
endforeach()