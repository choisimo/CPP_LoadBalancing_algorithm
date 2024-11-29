# 자동화 스크립트: setup_and_build.ps1
# 실행 시 관리자 권한 필요 (CMake, MinGW 다운로드 및 설치 포함)

# 설정
$project_dir = "C:\CPP_LoadBalancing_algorithm\team_report_24"  # 프로젝트 디렉토리 경로
$build_dir = "$project_dir\build"                              # 빌드 디렉토리

# 1. CMake 설치 확인 및 설치
Write-Host "CMake 설치 여부 확인 중..."
if (-not (Get-Command "cmake" -ErrorAction SilentlyContinue)) {
    Write-Host "CMake가 설치되어 있지 않습니다. 설치를 시작합니다..."
    Invoke-WebRequest -Uri "https://github.com/Kitware/CMake/releases/download/v3.28.2/cmake-3.28.2-windows-x86_64.msi" -OutFile "$env:TEMP\cmake_installer.msi"
    Start-Process msiexec.exe -ArgumentList "/i $env:TEMP\cmake_installer.msi /quiet" -Wait
    Write-Host "CMake 설치가 완료되었습니다."
} else {
    Write-Host "CMake가 이미 설치되어 있습니다."
}

# 2. MinGW 설치 확인 및 설치
Write-Host "MinGW 설치 여부 확인 중..."
$mingw_path = "C:\MinGW\bin"
if (-not (Test-Path $mingw_path)) {
    Write-Host "MinGW가 설치되어 있지 않습니다. 설치를 시작합니다..."
    Invoke-WebRequest -Uri "https://sourceforge.net/projects/mingw/files/latest/download" -OutFile "$env:TEMP\mingw_installer.exe"
    Start-Process -FilePath "$env:TEMP\mingw_installer.exe" -ArgumentList "/S /D=C:\MinGW" -Wait
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\MinGW\bin", [EnvironmentVariableTarget]::Machine)
    Write-Host "MinGW 설치가 완료되었으며, 환경 변수에 추가되었습니다."
} else {
    Write-Host "MinGW가 이미 설치되어 있습니다."
}

# 3. Git 설치 확인 (선택 사항)
Write-Host "Git 설치 여부 확인 중..."
if (-not (Get-Command "git" -ErrorAction SilentlyContinue)) {
    Write-Host "Git이 설치되어 있지 않습니다. 설치를 시작합니다..."
    Invoke-WebRequest -Uri "https://github.com/git-for-windows/git/releases/latest/download/Git-2.42.0-64-bit.exe" -OutFile "$env:TEMP\git_installer.exe"
    Start-Process -FilePath "$env:TEMP\git_installer.exe" -ArgumentList "/VERYSILENT" -Wait
    Write-Host "Git 설치가 완료되었습니다."
} else {
    Write-Host "Git이 이미 설치되어 있습니다."
}

# 4. 프로젝트 빌드
Write-Host "프로젝트 빌드를 시작합니다..."
if (-Not (Test-Path $build_dir)) {
    Write-Host "빌드 디렉토리가 없습니다. 새 디렉토리를 생성합니다."
    New-Item -ItemType Directory -Path $build_dir | Out-Null
}

cd $build_dir
Write-Host "CMake를 실행하여 빌드 파일을 생성 중..."
& cmake .. -G "MinGW Makefiles" | Out-Host
Write-Host "Makefile을 실행하여 컴파일 중..."
& mingw32-make | Out-Host

# 5. 실행
Write-Host "빌드가 완료되었습니다. 프로그램을 실행합니다..."
& .\CPP_LoadBalancing_algorithm.exe
