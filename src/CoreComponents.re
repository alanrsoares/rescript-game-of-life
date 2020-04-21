module Root = [%styled.div {|
  display: flex;
  color: white;
|}];

module AppBar = [%styled.div
  {|
    display: flex;
    text-align: center;
    justify-content: center;
    align-items: center;
    padding-top: 2rem;
    font-size: 2rem;
    line-height: 1rem;
  |}
];

module Content = [%styled.div {|
  width: 100%;
|}];