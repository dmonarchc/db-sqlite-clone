describe 'database' do 
  def run_script(commands)
    raw_output = nil
    IO.popen("./src/db", "r+") do |pipe|
      commands.each do |command|
        pipe.puts command
      end

      pipe.close_write


      # Read entire output
      raw_output = pipe.gets(nil)
    end
    raw_output.split("\n")
  end
  
  # Testea el funcionamiendo basico de la db
  it 'inserts and retrieves a row' do
    result = run_script([
      "insert 1 user1 person1@example.com",
      "select",
      ".exit",
    ])
    expect(result).to match_array([
      "db > Executed.",
      "db > (1, user1, person1@example.com)",
      "Executed.",
      "db > ",
    ])
  end

  # Imprime error cuando la tabla esta llena 
  it 'prints error message when table is full' do
    script = (1..1401).map do |i|
      "insert #{i} user#{i} person#{i} example.com"
    end
    script << ".exit"
    result = run_script(script)
    expect(result[-1]).to eq("db > ")
    #expect(result[-1]).to eq('db > Error: Table full.') Error corregido por que ahora usamos paginacion
  end

  # Error corregido tambien permitimos ingresar a tope considerando el ultimo caracter vacio
  it 'allows inserting strings that are the maximum length' do
    long_username = "a"*32
    long_email = "a"*255
    script = [
      "insert 1 #{long_username} #{long_email}",
      "select",
      ".exit",
    ]
    result = run_script(script)
    expect(result).to match_array([
      "db > Executed.",
      "db > (1, #{long_username}, #{long_email})",
      "Executed.",
      "db > ",
    ])
  end

  # Test de no existencia de persistencia en disco
  xit 'keeps data after closing connection' do
    result1 = run_script([
      "insert 1 user1 person1@example.com",
      ".exit"
    ])
    expect(result1).to match_array([
      "db > Executed.",
      "db > ",
    ])
    result2 = run_script([
      "select",
      ".exit",
    ])
    expect(result2).to match_array([
      "db > (1, user1, person1@example.com)",
      "Executed.",
      "db > ",
    ])
  end

  # Test de id debe ser positiva
  it 'prints an error message if id is negative' do
    script = [
      "insert -1 cstack foo@bar.com",
      "select",
      ".exit",
    ]
    result = run_script(script)
    expect(result).to match_array([
      "db > ID must be positive.",
      "db > Executed.",
      "db > ",
    ])
  end
end
